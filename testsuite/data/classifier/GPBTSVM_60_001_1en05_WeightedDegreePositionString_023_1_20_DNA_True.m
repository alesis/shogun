classifier_accuracy = 0.0001;
init_random = 42;
accuracy = 1e-08;
classifier_labels = [1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1];
seqlen = 60;
classifier_tube_epsilon = 0.01;
classifier_epsilon = 1e-05;
data_test = {'CAGAAAGACTCAGATATCACGTACGGTGCTATCTAACCATACCACACTAATTACCTTTGC', 'TTGCTGTGTGCTGGAGGAAGTGAGACAAACACGCCTAGAAGGTGTAAAAGGATTCAAAAG'};
data_type = '';
kernel_name = 'WeightedDegreePositionString';
classifier_type = 'kernel';
classifier_classified = [0.884272372, 0.889528569];
feature_type = 'Char';
classifier_C = 0.23;
name = 'GPBTSVM';
classifier_num_threads = 1;
data_train = {'TCAAGATTTCAGGTCCTCGAGAGGATGACATTTTGGCATTTGTCAGGCATGCGCCACTTC', 'TGTGGAAAATTCGCTTTCGCAAGTCTAGCAAGTCAGAGCCTCTTGAGTTCCTGCTGTGCA', 'CTGTCTCTGCGGAGAGAACGCGTGGCGGACGATGATCCAAAGCCACGGACGGACGCGTAG', 'AGCGCCATAATCGGGGAGACAGGTTTAGGCGCTTGGCTTCCATTGAAGTACGCTCTCTAG', 'AGTCAAAAGGAAAAGACAGCGGGTGGCGCACTCGCGTTCCTCCTACTGCCGACCGGACTG', 'TTTAGATTGTGCCCATAGTTGTCAACTTACAAAACTTTAATGTACATCATTTGTGTGATC', 'ATTGCGTGGCGACTAGTTCACGCAATGTACTTTTCTTAAACATTCCACGAATACTGACAC', 'ACGTCTTAGCCCCATGCACAAATTGCCGTGAAATTCATCACTCGTTACGGAGTAAGGATT', 'TGTATTCTTGCTGCAGTCCCTCAAACAGTTTAGCTCCACAGCGAGCGTGCATGAAGAGAC', 'TCCAGACCTCTACTCTCTTGCATGCGGCCTCACGCAAAGGTTTGTGGAGCTTGGAATGGT', 'TTGGTGCCATAAGAATATAGAACGTCCCATATACATCCGGTACGAGGTCCGGCGGAATGT'};
feature_class = 'string';
classifier_bias = 0.879942474502;
kernel_arg0_degree = 20;
classifier_alphas = [0.125793255, -0.23, 0.116635711, 0.13610521, 0.131885931, 0.1416093, -0.23, -0.23, 0.13803529, -0.23, 0.129935303];
alphabet = 'DNA';
classifier_support_vectors = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
classifier_linadd_enabled = 'True';
data_class = 'dna';