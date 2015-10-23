int main( int argc, char** argv ) {
pthread_t threads[NUM_CPUS];
	void* returnValue;
	for ( int i = 0; i < NUM_CPUS; ++i ) {
		parameter_t* params = malloc( sizeof ( parameter_t ) );
		params->startIndex = i * (ARRAY_SIZE / NUM_CPUS);
	int end = (i + 1) * (ARRAY_SIZE / NUM_CPUS);
	if ( i == (NUM_CPUS - 1) ) {
		end = ARRAY_SIZE;
}
	params->endIndex = end;
	params->searchValue = SEARCH_VALUE;
	pthread_create(&threads[i], NULL, search, params);
}

for ( int i = 0; i < NUM_CPUS; ++i ) {
	pthread_join( threads[i], &returnValue );
	int *rv = (int *) returnValue;
if ( -1 != *rv ) {
	printf("Found at %d\n", *rv);
}
	free( returnValue );
}
	pthread_exit(0);
}
