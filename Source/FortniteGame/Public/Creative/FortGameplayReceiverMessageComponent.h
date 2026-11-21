// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/MemberReference.h"
#include "Creative/FortGameplayMessageComponentBase.h"
#include "FortGameplayReceiverMessageComponent.generated.h"

class AController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChannelIdLoaded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayMessageReceived, AController*, TriggerInstigator);

USTRUCT()
struct FFortGameplayReceiverEventFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Event Router")
	FMemberReference EventFunction;

};

USTRUCT()
struct FFortLegacyGameplayMessageEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AController> Instigator;

};

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortGameplayReceiverMessageComponent : public UFortGameplayMessageComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnGameplayMessageReceived OnGameplayMessageReceived;

	UPROPERTY(EditDefaultsOnly, Category="Channel")
	FFortGameplayReceiverEventFunction EventFunction;

};

