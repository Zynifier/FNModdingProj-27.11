// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundPatchWrapper.h"
#include "HarmonixDsp/AudioAnalysis/FFTAnalyzer.h"
#include "FabricMetasoundInstrumentPlayerPatchWrapper.generated.h"

class UFusionPatch;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundPatchWrapperFFTResultsUpdated, const FHarmonixFFTAnalyzerResults&, FFTAnalyzerResults);

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundInstrumentPlayerPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MetaSound")
	void DriveFFTDataOnPrimitive(UPrimitiveComponent* Primitive);

	UFUNCTION(BlueprintCallable, Category="MetaSound")
	void SetFusionPatch(UFusionPatch* FusionPatch);

	UPROPERTY(BlueprintAssignable)
	FOnFabricMetaSoundPatchWrapperFFTResultsUpdated OnFFTResultsUpdated;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundInstrumentPlayerPatchWrapper")
	FFabricMetaSoundPatchWrapperBinding FFTAnalysisOutputBinding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundInstrumentPlayerPatchWrapper")
	int32 FFTCPDStartIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundInstrumentPlayerPatchWrapper")
	int32 FFTLength;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFusionPatch> CurrentFusionPatch;

};

