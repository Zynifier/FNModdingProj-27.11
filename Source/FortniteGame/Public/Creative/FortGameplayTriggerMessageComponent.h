// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/MemberReference.h"
#include "Creative/FortGameplayMessageComponentBase.h"
#include "IGameplayEventLegacyBroadcast.h"
#include "FortGameplayTriggerMessageComponent.generated.h"

class AController;

USTRUCT()
struct FFortGameplayTriggerEventDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Event Router")
	FMemberReference EventDescriptor;

};

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortGameplayTriggerMessageComponent : public UFortGameplayMessageComponentBase, public IGameplayEventLegacyBroadcast
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SendTriggerMessage(AController* TriggerInstigator);

	UPROPERTY(EditDefaultsOnly, Category="Channel")
	FFortGameplayTriggerEventDescriptor EventDescriptor;

};

