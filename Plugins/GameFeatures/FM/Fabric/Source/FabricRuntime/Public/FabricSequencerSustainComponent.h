// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Math/MathFwd.h"
#include "FabricStepSequencerComponent.h"
#include "FabricSequencerSustainComponent.generated.h"

class UFabricStepSequencerComponent;
class UFabricStepSequencerGridComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFabricSequencerSustainComponent : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain", meta=(CallInEditor="true"))
	void InitializeSustainComponent(UFabricStepSequencerComponent* InStepSequencer, UFabricStepSequencerGridComponent* InStepSequencerGrid);

protected:
	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void AddSustainInstance(int32 StepIndex, int32 TrackIndex);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	float CalculateSustainLength(float NumStepsCoveredBySustain);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void ConstructSustains();

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void FindAndDeleteInstance(int32 StepIndex, int32 TrackIndex);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void FindHeadNoteAndUpdateInstance(int32 StepIndex, int32 TrackIndex);

	UFUNCTION()
	void OnFullTableChanged();

	UFUNCTION()
	virtual void OnNumStepsChanged(int32 NumSteps);

	UFUNCTION()
	virtual void OnNumTracksChanged(int32 NumTracks);

	UFUNCTION()
	virtual void OnPageChanged(int32 CurrentPage);

	UFUNCTION()
	void OnStepChanged(const FFabricSequencerStepChangedInfo& StepInfo);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void SetEndBeat(int32 InstanceIndex, float EndBeatValue);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void SetLoopBeat(int32 InstanceIndex, float LoopBeatValue);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void SetStartBeat(int32 InstanceIndex, float StartBeatValue);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void UpdateDeviceEnabledOnSustain(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void UpdatePipsOnGridChanged();

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void UpdateSustainInstance(int32 StepIndex, int32 TrackIndex, int32 PageIndex, bool bEnabled, bool bContinuous, bool bStepChanged);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void UpdateSustainMaterial(int32 InstanceIndex, int32 HeadNoteStepIndex, int32 TrackIndex);

	UFUNCTION(BlueprintCallable, Category="FabricSequencerSustain")
	void UpdateVisibilityOfInstances();

	UPROPERTY(Transient)
	TMap<FIntVector2, int32> StepToInstanceMapping;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	int32 PICDStartBeat;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	int32 PICDEndBeat;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	int32 PICDLoopBeat;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	int32 CPDDeviceEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig", meta=(ClampMin="1.000000"))
	float GridSquareExtents;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	float SustainInstanceYLocation;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	float SustainInstanceYScale;

	UPROPERTY(EditDefaultsOnly, Category="FabricSequencerSustainConfig")
	float SustainInstanceZScale;

private:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFabricStepSequencerComponent> StepSequencer;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFabricStepSequencerGridComponent> StepSequencerGrid;

};

