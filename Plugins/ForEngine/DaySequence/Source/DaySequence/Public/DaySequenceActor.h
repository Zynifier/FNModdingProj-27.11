// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "IMovieScenePlaybackClient.h"
#include "Misc/Timecode.h"
#include "MovieSceneBindingOwnerInterface.h"
#include "DaySequenceActor.generated.h"

class UCurveFloat;
class UDaySequence;
class UDaySequencePlayer;
class UMovieSceneBindingOverrides;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeOfDayPreviewChanged, float, Time);

USTRUCT()
struct FDaySequenceAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sequence", meta=(AllowedClasses="/Script/DaySequence.DaySequence"))
	TObjectPtr<UDaySequence> Sequence;

	UPROPERTY(EditAnywhere, Category="Sequence")
	int32 Bias;

	UPROPERTY(EditAnywhere, Category="Sequence")
	bool bMuted;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class DAYSEQUENCE_API ADaySequenceActor : public AInfo, public IMovieScenePlaybackClient, public IMovieSceneBindingOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sequence")
	bool ContainsDaySequence(const UDaySequence* InDaySequence);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	int32 GetBias(FName SequenceKey);

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetDayLength() const;

	UFUNCTION(BlueprintPure, Category="Sequence")
	UDaySequence* GetDaySequence(FName SequenceName) const;

	UFUNCTION(BlueprintPure, Category="Sequence")
	UDaySequence* GetFirstDaySequence() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetInitialTimeOfDay() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	UDaySequencePlayer* GetSequencePlayer() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetStaticTimeOfDay() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetTimeOfDay() const;

#if WITH_EDITOR
	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetTimeOfDayPreview() const;
#endif

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	float GetTimePerCycle() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	bool HasStaticTimeOfDay() const;

	UFUNCTION(BlueprintCallable, Category="Sequence")
	bool IsMuteSequence(FName SequenceKey);

	UFUNCTION(BlueprintPure, Category="Playback")
	bool IsPaused() const;

	UFUNCTION(BlueprintPure, Category="Playback")
	bool IsPlaying() const;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetTimePerCycle(float InHours);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void MuteSequence(FName SequenceKey, bool bState);

	UFUNCTION(BlueprintCallable, Category="Playback")
	void Pause();

	UFUNCTION(BlueprintCallable, Category="Playback")
	void Play();

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void RemoveStaticTimeOfDay(bool bResumeFromStaticTime = false);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetBias(FName SequenceKey, int32 Bias);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetDaySequence(FName SequenceName, UDaySequence* InDaySequence);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetReplicatePlayback(bool ReplicatePlayback);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void SetStaticTimeOfDay(float InHours);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	bool SetTimeOfDay(float InHours);

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void SetTimeOfDayPreview(float InHours);
#endif

	UPROPERTY(BlueprintGetter=GetSequencePlayer, Transient, Replicated, Instanced, Category="Playback", meta=(ExposeFunctionCategories="Sequencer|Player"))
	TObjectPtr<UDaySequencePlayer> SequencePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="RuntimeDayCycle", meta=(DisplayAfter="bRunDayCycle", EditCondition="bUseInterpCurve"))
	TObjectPtr<UCurveFloat> DayInterpCurve;

	UPROPERTY(EditAnywhere, Category="Sequence")
	TMap<FName, FDaySequenceAssetData> DaySequences;

	UPROPERTY(BlueprintReadOnly, Instanced, Category="Sequence")
	TObjectPtr<UMovieSceneBindingOverrides> BindingOverrides;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetReplicatePlayback, Category="Replication", meta=(DisplayName="Replicate Playback"))
	uint8 bReplicatePlayback : 1;

	virtual bool RetrieveBindingOverrides(const FGuid& InBindingId, FMovieSceneSequenceID InSequenceID, TArray<UObject*, TInlineAllocator<1>>& OutObjects) const override;

	virtual UObject* GetInstanceData() const override;

	virtual UMovieSceneSequence* RetrieveOwnedSequence() const override;

	virtual TSharedPtr<FStructOnScope> GetObjectPickerProxy(TSharedPtr<IPropertyHandle> ObjectPropertyHandle) override;

	virtual void UpdateObjectFromProxy(FStructOnScope& Proxy, IPropertyHandle& ObjectPropertyHandle) override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UDaySequence> RootSequence;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, NonTransactional, Category="Preview")
	FTimecode TimeOfDayPreview;
#endif

	UPROPERTY(EditAnywhere, Category="RuntimeDayCycle")
	bool bRunDayCycle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="RuntimeDayCycle", meta=(InlineEditConditionToggle))
	bool bUseInterpCurve;

	UPROPERTY(EditAnywhere, Category="RuntimeDayCycle")
	FTimecode DayLength;

	UPROPERTY(EditAnywhere, Category="RuntimeDayCycle")
	FTimecode TimePerCycle;

	UPROPERTY(EditAnywhere, Category="RuntimeDayCycle")
	FTimecode InitialTimeOfDay;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnTimeOfDayPreviewChanged OnTimeOfDayPreviewChanged;
#endif

};

