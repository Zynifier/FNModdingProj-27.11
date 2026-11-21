// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IMovieSceneSequencePlayerObserver.h"
#include "MovieSceneSequencePlaybackSettings.h"
#include "Building/BuildingProp.h"
#include "Minigame/FortMinigameTypes.h"
#include "CinematicSequenceDeviceBase.generated.h"

class AFortPlayerController;
class ALevelSequenceActor;
class ULevelSequence;
class ULevelSequencePlayer;
class UMovieSceneSequencePlayer;

UENUM(BlueprintType)
enum class ECinematicSequenceEnabledOnPhase : uint8
{
	// Any minigame state

	Always = 0 UMETA(DisplayName="Always"),
	// EFortMinigameState::PreGame (island in read only state)

	PreGameOnly = 1 UMETA(DisplayName="Pre-Game Only"),
	// EFortMinigameState::InProgress

	GameplayOnly = 2 UMETA(DisplayName="Gameplay Only"),
	// EFortMinigameState::PreGame (island is NOT in read only state)

	CreateOnly = 3 UMETA(DisplayName="Create Only"),
};

UENUM(BlueprintType)
enum class ECinematicSequenceVisibility : uint8
{
	// This device will only be played back for the instigating player

	InstigatorOnly = 0 UMETA(DisplayName="Instigator Only"),
	// This device will only be played back for the instigating player's team

	InstigatingTeam = 1 UMETA(DisplayName="Instigator's Team"),
	// This device will be played back for everyone

	Everyone = 2 UMETA(DisplayName="Everyone"),
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ACinematicSequenceDeviceBase : public ABuildingProp, public IMovieSceneSequencePlayerObserver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Sequence")
	int32 GetPlaybackFrame() const;

	UFUNCTION(BlueprintPure, Category="Sequence")
	float GetPlaybackTime() const;

	UFUNCTION(BlueprintPure, Category="Sequence")
	float GetPlayRate() const;

	UFUNCTION(BlueprintPure, Category="Sequence")
	UMovieSceneSequencePlayer* GetSequencePlayer() const;

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void GoToEndAndStop();

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void Pause();

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void Play();

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetPlaybackFrame(int32 Frame);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetPlaybackTime(float Time);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetPlayRate(float PlayRate);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void SetSequence(ULevelSequence* Sequence);

	UFUNCTION(BlueprintCallable, Category="Sequence")
	void Stop();

	virtual bool CanObserveSequence() const override;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Sequence")
	void HandleSequencePlayerCreated(ULevelSequencePlayer* Player);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	TObjectPtr<ULevelSequence> Sequence;

	UPROPERTY()
	TObjectPtr<ALevelSequenceActor> LevelSequenceActor;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Instigator")
	TObjectPtr<AFortPlayerController> InstigatingController;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Instigator")
	uint8 InstigatingTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	uint8 bLoopPlayback : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY(SaveGame, meta=(DeprecatedProperty, DeprecationMessage="Use Settings.FinishCompletionStateOverride instead"))
	uint8 bRestoreState_DEPRECATED : 1;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	uint8 bAutoPlay : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY(SaveGame, meta=(DeprecatedProperty, DeprecationMessage="Use EnabledOnPhase instead"))
	EFortMinigameState AutoPlayMinigameState_DEPRECATED;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(EditCondition="bAutoPlay"))
	ECinematicSequenceEnabledOnPhase EnabledOnPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(DisplayName="Visibility"))
	ECinematicSequenceVisibility Visibility;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions|Basic")
	bool bLevelSequenceActorAlwaysRelevant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	float PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	EMovieSceneCompletionModeOverride FinishCompletionStateOverride;

};

