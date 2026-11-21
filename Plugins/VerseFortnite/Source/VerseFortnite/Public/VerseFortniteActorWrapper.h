// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseFortniteActorWrapper.generated.h"

class AActor;

UCLASS()
class UVerseFortniteActorWrapper : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnActorDestroyed(AActor* DestroyedActor);

};

