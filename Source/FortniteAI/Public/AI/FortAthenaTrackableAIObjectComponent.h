// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaTrackableAIObjectInterface.h"
#include "FortAthenaTrackableAIObjectComponent.generated.h"

class UObject;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAthenaTrackableAIObjectComponent : public UActorComponent, public IFortAthenaTrackableAIObjectInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer GameplayTags;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaTrackableAIObjectComponent", meta=(AllowAbstract, AllowPrivateAccess="true"))
	TSubclassOf<UObject> CustomRegistrationClass;

};

