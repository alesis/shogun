require("Classifier")
require("Distribution")
require("Kernel")
require("Regression");
require("Clustering");
require("Evaluation");
require("Library");
require("Structure");
require("Distance");
require("Features");
require("Preprocessor");
DistanceMachine = Classifier.DistanceMachine
KernelMachine = Classifier.KernelMachine
KernelPerceptron = Classifier.KernelPerceptron
KNN = Classifier.KNN
KRR = Classifier.KRR
LDA = Classifier.LDA
KMeans = Classifier.KMeans
Hierarchical = Classifier.Hierarchical
LinearClassifier = Classifier.LinearClassifier
LPBoost = Classifier.LPBoost
LPM = Classifier.LPM
Perceptron = Classifier.Perceptron
PluginEstimate = Classifier.PluginEstimate
SubGradientLPM = Classifier.SubGradientLPM
GHMM = Distribution.GHMM
Histogram = Distribution.Histogram
HMM = Distribution.HMM
LinearHMM = DistributionLinearHMM
ANOVAKernel = Kernel.ANOVAKernel
AUCKernel = Kernel.AUCKernel
CauchyKernel = Kernel.CauchyKernel
Chi2Kernel = Kernel.Chi2Kernel
CombinedKernel = Kernel.CombinedKernel
CommUlongStringKernel = Kernel.CommUlongStringKernel
CommWordStringKernel = Kernel.CommWordStringKernel
ConstKernel = Kernel.ConstKernel
CustomKernel = Kernel.CustomKernel
DiagKernel = Kernel.DiagKernel
DistanceKernel = Kernel.DistanceKernel
DotKernel = Kernel.DotKernel
ExponentialKernel = Kernel.ExponentialKernel
FixedDegreeStringKernel = Kernel.FixedDegreeStringKernel
GaussianKernel = Kernel.GaussianKernel
GaussianMatchStringKernel = Kernel.GaussianMatchStringKernel
GaussianShiftKernel = Kernel.GaussianShiftKernel
GaussianShortRealKernel = Kernel.GaussianShortRealKernel
HistogramIntersectionKernel = Kernel.HistogramIntersectionKernel
HistogramWordStringKernel = Kernel.HistogramWordStringKernel
LinearKernel = Kernel.LinearKernel
LinearStringKernel = Kernel.LinearStringKernel
LocalAlignmentStringKernel = Kernel.LocalAlignmentStringKernel
LocalityImprovedStringKernel = Kernel.LocalityImprovedStringKernel
LogKernel = Kernel.LogKernel
MatchWordStringKernel = Kernel.MatchWordStringKernel
OligoStringKernel = Kernel.OligoStringKernel
PolyKernel = Kernel.PolyKernel
PolyMatchStringKernel = Kernel.PolyMatchStringKernel
PolyMatchWordStringKernel = Kernel.PolyMatchWordStringKernel
PowerKernel = Kernel.PowerKernel
PyramidChi2 = Kernel.PyramidChi2
RegulatoryModulesStringKernel = Kernel.RegulatoryModulesStringKernel
SalzbergWordStringKernel = Kernel.SalzbergWordStringKernel
SigmoidKernel = Kernel.SigmoidKernel
SimpleLocalityImprovedStringKernel = Kernel.SimpleLocalityImprovedStringKernel
SNPStringKernel = Kernel.SNPStringKernel
SparseKernel = Kernel.SparseKernel
SparseSpatialSampleStringKernel = Kernel.SparseSpatialSampleStringKernel
SpectrumMismatchRBFKernel = Kernel.SpectrumMismatchRBFKernel
SpectrumRBFKernel = Kernel.SpectrumRBFKernel
SphericalKernel = Kernel.SphericalKernel
SplineKernel = Kernel.SplineKernel
StringKernel = Kernel.StringKernel
TensorProductPairKernel = Kernel.TensorProductPairKernel
TStudentKernel = Kernel.TStudentKernel
WaveKernel = Kernel.WaveKernel
WaveletKernel = Kernel.WaveletKernel
WeightedCommWordStringKernel = Kernel.WeightedCommWordStringKernel
WeightedDegreePositionStringKernel = Kernel.WeightedDegreePositionStringKernel
WeightedDegreeRBFKernel = Kernel.WeightedDegreeRBFKernel
WeightedDegreeStringKernel = Kernel.WeightedDegreeStringKernel
BrayCurtisDistance = Distance.BrayCurtisDistance
CanberraMetric = Distance.CanberraMetric
CanberraWordDistance = Distance.CanberraWordDistance
ChebyshewMetric = Distance.ChebyshewMetric
ChiSquareDistance = Distance.ChiSquareDistance
CosineDistance = Distance.CosineDistance
CustomDistance = Distance.CustomDistance
EuclidianDistance = Distance.EuclidianDistance
GeodesicMetric = Distance.GeodesicMetric
HammingWordDistance = Distance.HammingWordDistance
JensenMetric = Distance.JensenMetric
KernelDistance = Distance.KernelDistance
ManhattanMetric = Distance.ManhattanMetric
ManhattanWordDistance = Distance.ManhattanWordDistance
MinkowskiMetric = Distance.MinkowskiMetric
RealDistance = Distance.RealDistance
SimpleDistance = Distance.SimpleDistance
SparseDistance = Distance.SparseDistance
SparseEuclidianDistance = Distance.SparseEuclidianDistance
StringDistance = Distance.StringDistance
TanimotoDistance = Distance.TanimotoDistance
AttributeFeatures = Features.AttributeFeatures
CombinedDotFeatures = Features.CombinedDotFeatures
CombinedFeatures = Features.ombinedFeatures
DotFeatures = Features.DotFeatures
DummyFeatures = Features.DummyFeatures
ExplicitSpecFeatures = Features.ExplicitSpecFeatures
FKFeatures = Features.FKFeatures
HashedWDFeatures = Features.HashedWDFeatures
HashedWDFeaturesTransposed = Features.HashedWDFeaturesTransposed
ImplicitWeightedSpecFeatures = Features.ImplicitWeightedSpecFeatures
Labels = Features.Labels
LBPPyrDotFeatures = Features.LBPPyrDotFeatures
PolyFeatures = Features.PolyFeatures
RealFileFeatures = Features.RealFileFeatures
SimpleFeatures = Features.SimpleFeatures
SNPFeatures = Features.SNPFeatures
SparseFeatures = Features.SparseFeatures
SparsePolyFeatures = Features.SparsePolyFeatures
StringFeatures = Features.StringFeatures
StringFileFeatures = Features.StringFileFeatures
TOPFeatures = Features.TOPFeatures
WDFeatures = Features.WDFeatures
RealFeatures = Features.RealFeatures
KernelPCACut = Preprocessor.KernelPCACut
LogPlusOne = Preprocessor.LogPlusOne
NormDerivativeLem3 = Preprocessor.NormDerivativeLem3
NormOne = Preprocessor.NormOne
PCACut = Preprocessor.PCACut
PruneVarSubMean = Preprocessor.PruneVarSubMean
PruneVarSubMean = Preprocessor.PruneVarSubMean
RandomFourierGauss = Preprocessor.PreprocRandomFourierGaussPreproc
RandomFourierGauss = Preprocessor.PreprocRandomFourierGaussPreproc
SimplePreprocessor = Preprocessor.SimplePreprocessor
SortUlongString = Preprocessor.SortUlongString
SortWordString = Preprocessor.SortWordString
SortWordString = Preprocessor.SortWordString
SparsePreprocessor = Preprocessor.SparsePreprocessor
StringPreprocessor = Preprocessor.StringPreprocessor
