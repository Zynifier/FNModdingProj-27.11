// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "FabricStepSequencerComponent.h"
#include "FabricSteppedPreviewFXComponent.generated.h"

enum class EFabricNoteStyle : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFabricSteppedPreviewFXComponent : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX", meta=(CallInEditor="true"))
	virtual void ConstructPreviewVisuals(int32 NumSteps, float StepBeatLength, bool bInTestNotesOn = false);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void UpdateDeviceEnabledFX(bool bEnabled);

protected:
	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	virtual float GetNoteOn(int32 InstanceIndex);

	UFUNCTION()
	virtual void OnBeatOffsetChanged(float BeatOffset);

	UFUNCTION()
	virtual void OnBeatScaleChanged(float BeatScale);

	UFUNCTION()
	virtual void OnNoteStyleChanged(EFabricNoteStyle Style);

	UFUNCTION()
	virtual void OnNumStepsChanged(int32 NumSteps);

	UFUNCTION()
	virtual void OnNumTracksChanged(int32 NumTracks);

	UFUNCTION()
	virtual void OnPageChanged(int32 CurrentPage);

	UFUNCTION()
	virtual void OnQuarterNotesLengthChanged(float QuarterNoteLength);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetGenericFloatValue(int32 InstanceIndex, float FloatValue, bool bMarkRenderStateDirty);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetNoteLength(int32 InstanceIndex, float NoteLengthBeats);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetNoteOn(int32 InstanceIndex, float NoteOn, bool bMarkRenderStateDirty);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetNoteTime(int32 InstanceIndex, float NoteTimeOffsetBeats);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetNumSteps(int32 NumSteps);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetSpanLength(int32 InstanceIndex, float SpanLengthBeats);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	virtual void UpdateAllCurrentStepData(int32 NumSteps, float StepLengthBeats);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX", meta=(BlueprintProtected))
	virtual void UpdateStepData(int32 Index, bool bMarkRenderStateDirty = false);

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX")
	int32 NumberOfSteps;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX")
	bool bManuallySpaceMeshInstances;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances"))
	bool bAlignToTransformCenter;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances && bAlignToTransformCenter"))
	float CenterAlignmentBounds;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances && !bAlignToTransformCenter"))
	float DistanceBetweenInstances;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances && !bAlignToTransformCenter"))
	float DistanceBetweenTripletIntances;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances && !bAlignToTransformCenter"))
	float DistanceBetweenInstanceSets;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|ManualSpacing", meta=(DisplayAfter="ManuallySpaceMeshInstances", Editcondition="bManuallySpaceMeshInstances && !bAlignToTransformCenter"))
	float DistanceBetweenTripletInstanceSets;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricSteppedPreviewFX|Testing")
	bool bTestNotesOn;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Testing")
	float TestNoteLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Testing")
	float TestSpanLength;
#endif

	UPROPERTY(Transient)
	EFabricNoteStyle NoteStyle;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 CPDDeviceEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 CPDNumSteps;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 PICDNoteOn;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 PICDNoteLength;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 PICDSpanLength;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 PICDNoteTime;

	UPROPERTY(EditDefaultsOnly, Category="FabricSteppedPreviewFX|Config")
	int32 PICDGenericFloatIndex;

	UPROPERTY()
	float LengthStepBeats;

	UPROPERTY()
	float StepLengthQuarterNotes;

	UPROPERTY()
	float StepBeatScale;

	UPROPERTY()
	float StepBeatOffset;

	UPROPERTY(Transient)
	float LengthTrackBeats;

	UPROPERTY(Transient)
	double InstanceSpace;

	UPROPERTY(Transient)
	double InstanceSetSpace;

};

