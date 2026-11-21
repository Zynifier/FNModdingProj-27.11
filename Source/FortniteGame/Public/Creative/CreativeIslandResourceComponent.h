// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeIslandResourceComponent.generated.h"

class UCreativeIslandResourceManagerComponent;

UCLASS(meta=(BlueprintSpawnableComponent))
class UCreativeIslandResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFreeResourcesSignature, UCreativeIslandResourceManagerComponent*, ResourceManager);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRequestResourcesSignature, UCreativeIslandResourceManagerComponent*, ResourceManager);

public:
	UPROPERTY(BlueprintAssignable)
	FRequestResourcesSignature RequestResourcesDelegate;

	UPROPERTY(BlueprintAssignable)
	FFreeResourcesSignature FreeResourcesDelegate;

};

