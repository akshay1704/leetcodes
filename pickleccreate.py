import pickle

dict = {
	"ip":"34.125.120.91",
	"port": "9999",
	"name": "/execute_query",
	"ubit_name":"hamzaha2"
}

pickle_out = open('project2_index_details.pickle','wb')
pickle.dump(dict,pickle_out)
pickle_out.close()