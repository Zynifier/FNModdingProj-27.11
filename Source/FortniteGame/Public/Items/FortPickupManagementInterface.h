// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPickupManagementInterface.generated.h"

class AActor;

UENUM()
enum class EManagedPickupBucket : uint8
{
	Default = 0,
	// Sort into appropriate bucket

	Junk = 1,
	Normal = 2,
	Important = 3,
};

UENUM()
enum class EManagedPickupContext : uint8
{
	Unknown = 0,
	// No additional context available

	PlayerDropped = 1,
	Overflow = 2,
	Spawned = 3,
};

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortPickupManagementInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortPickupManagementInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupManagement", meta=(DefaultToSelf="ActorToManage"))
	virtual void AddManagedActor(AActor* ActorToManage, UPARAM(ref) FString& BucketName, float Weight = 0.010000f, bool bPerPlayer = true);

};

