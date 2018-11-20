from cgi import parse_qs
import json
from game import new_game, guess


def application(environ, start_response):

	error = False
	
	if environ['REQUEST_METHOD'] != 'POST':
		response = {'code': 'error', 'msg': 'wrong HTTP method'}
		error = True

	if not error:
		try:
			path = environ['PATH_INFO'].split('/')
			if len(path) == 2:
				method = path[1]
			else:
				response = {'code': 'error', 'msg': 'wrong API path'}
				error = True
		except:
			response = {'code': 'error', 'msg': 'wrong API path'}
			error = True

	try:
		request_body_size = int(environ.get('CONTENT_LENGTH', '0'))
	except ValueError:
		request_body_size = 0

	request_body = environ['wsgi.input'].read(request_body_size)
	d = parse_qs(request_body)

	if not error:
		if method == 'new':
			response = new_game()
		elif method == 'guess':
			response = guess(d)
		else:
			response = {'code': 'error', 'msg': 'non-existent API method'}

	status = '200 OK'
	response_body = json.dumps(response)

	response_headers = [
		('Content-Type', 'application/json'),
		('Content-Length', str(len(response_body)))
	]

	start_response(status, response_headers)

	return [response_body]

