// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VerseFortniteSubsystem.generated.h"

class AActor;
class UVerseFortniteActorWrapper;

UCLASS()
class VERSEFORTNITE_API UVerseFortniteSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<TWeakObjectPtr<AActor>, TObjectPtr<UVerseFortniteActorWrapper>> ActorToWrapperMap;

};

