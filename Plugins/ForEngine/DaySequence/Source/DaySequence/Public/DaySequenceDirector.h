// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/QualifiedFrameTime.h"
#include "MovieSceneObjectBindingID.h"
#include "UObject/NoExportTypes.h"
#include "DaySequenceDirector.generated.h"

class AActor;
class UDaySequencePlayer;
class UMovieSceneSequence;
class UObject;

UCLASS(BlueprintType, Blueprintable)
class DAYSEQUENCE_API UDaySequenceDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sequencer|Director")
	AActor* GetBoundActor(FMovieSceneObjectBindingID ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Sequencer|Director")
	TArray<AActor*> GetBoundActors(FMovieSceneObjectBindingID ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Sequencer|Director")
	UObject* GetBoundObject(FMovieSceneObjectBindingID ObjectBinding);

	UFUNCTION(BlueprintCallable, Category="Sequencer|Director")
	TArray<UObject*> GetBoundObjects(FMovieSceneObjectBindingID ObjectBinding);

	UFUNCTION(BlueprintPure, Category="Sequencer|Director")
	FQualifiedFrameTime GetCurrentTime() const;

	UFUNCTION(BlueprintPure, Category="Sequencer|Director", meta=(DeprecatedFunction, DeprecationMessage="GetMasterSequenceTime is deprecated. Please use GetRootSequenceTime instead"))
	FQualifiedFrameTime GetMasterSequenceTime() const;

	UFUNCTION(BlueprintPure, Category="Sequencer|Director")
	FQualifiedFrameTime GetRootSequenceTime() const;

	UFUNCTION(BlueprintCallable, Category="Sequencer|Director")
	UMovieSceneSequence* GetSequence();

	UFUNCTION(BlueprintImplementableEvent, Category="Sequencer")
	void OnCreated();

	UPROPERTY(BlueprintReadOnly, Category="Cinematics")
	TObjectPtr<UDaySequencePlayer> Player;

	UPROPERTY()
	int32 SubSequenceID;

	UPROPERTY()
	int32 MovieScenePlayerIndex;

};

