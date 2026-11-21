// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PhysicsEngine/PhysicsCollisionHandler.h"
#include "UObject/NoExportTypes.h"
#include "FortPhysicsCollisionHandler.generated.h"

class UFortPhysicsCollisionResponse;

USTRUCT()
struct FCollisionResponseBaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="CollisionResponseBaseData")
	FGameplayTag HitSourceTag;

	UPROPERTY(EditAnywhere, Config, Category="CollisionResponseBaseData")
	FGameplayTag HitTargetTag;

	UPROPERTY(EditAnywhere, Category="CollisionResponseBaseData")
	bool bBlockOtherResponsesOnTagMatch;

	UPROPERTY(EditAnywhere, Category="CollisionResponseBaseData")
	bool bEnableTelemetry;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("UObject", "Object"))
class UFortPhysicsCollisionHandler : public UPhysicsCollisionHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Instanced, Category="FortPhysicsCollisionHandler")
	TArray<TObjectPtr<UFortPhysicsCollisionResponse>> CollisionResponses;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UFortPhysicsCollisionResponse : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Options", meta=(DisplayPriority="1"))
	bool bResponseEnabledOnServer;

	UPROPERTY(EditAnywhere, Category="Options", meta=(DisplayPriority="1"))
	bool bResponseEnabledOnClient;

	UPROPERTY(EditAnywhere, Category="Options", meta=(DisplayPriority="1"))
	int32 Priority;

};

