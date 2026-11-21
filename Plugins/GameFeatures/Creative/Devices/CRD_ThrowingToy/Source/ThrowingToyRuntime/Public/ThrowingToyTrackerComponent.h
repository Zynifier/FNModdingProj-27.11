// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ThrowingToyTrackerComponent.generated.h"

class AActor;
enum class EThrowingToyItemRemovedReason : uint8;

UENUM(BlueprintType)
enum class EThrowingToyItemRemovedReason : uint8
{
	None = 0,
	ManuallyDropped = 1,
	DeviceForcedDropped = 2,
	DeviceForcedDeleted = 3,
};

USTRUCT(BlueprintType)
struct FThrowingToyData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ThrowingToyData")
	TObjectPtr<AActor> ThrowingToy;

	UPROPERTY(BlueprintReadOnly, Category="ThrowingToyData")
	FGuid WorldItemGuid;

};

USTRUCT()
struct FThrowingToyDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FThrowingToyData> Entries;

};

UCLASS()
class UThrowingToyTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddThrowingToy(AActor* ThrowingToyActor, const FGuid& WorldItemGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AActor* GetAndReleaseThrowingToy(const FGuid& WorldItemGuid);

	UFUNCTION(BlueprintPure)
	EThrowingToyItemRemovedReason GetRecentThrowingToyItemRemovedReason();

	UFUNCTION(BlueprintCallable)
	AActor* GetThrowingToy(const FGuid& WorldItemGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRecentThrowingToyItemRemovedReason(EThrowingToyItemRemovedReason RemovedReason);

protected:
	UPROPERTY(Replicated)
	FThrowingToyDataArray ThrowingToysData;

};

