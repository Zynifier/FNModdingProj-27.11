// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "LootControllerNativeComponent.generated.h"

class AActor;
class ABuildingContainer;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsyncGetActorsOfClass, bool, bSuccess);

USTRUCT(BlueprintType)
struct FBuildingContainersArrayEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersArrayEntry")
	ABuildingContainer* BuildingContainer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersArrayEntry")
	FTransform Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersArrayEntry")
	FName SearchLootTierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersArrayEntry")
	FGameplayTagContainer GamePlayTags;

};

USTRUCT(BlueprintType)
struct FBuildingContainersFoundEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersFoundEntry")
	FGameplayTag GameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingContainersFoundEntry")
	TArray<FBuildingContainersArrayEntry> BuildingContainers;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class LOOTCONTROLLER_API ULootControllerNativeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(ArrayParm="InOutBuildingContainersFoundArray"))
	void AddToArray(UPARAM(ref) TArray<FBuildingContainersFoundEntry>& InOutBuildingContainersFoundArray, const int32 InBuildingContainerFoundIndex, const FBuildingContainersArrayEntry& InBuildingContainerToAdd);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	void AsyncGetActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintPure)
	bool IsRemoveLootEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsThrottleEnabled() const;

	UFUNCTION(BlueprintCallable)
	void PrintDebugString(const FString& DebugString, const bool LogWarning = false);

	UPROPERTY(BlueprintReadOnly, Transient, Category="LootControllerNativeComponent")
	TArray<AActor*> OutActors;

	UPROPERTY(BlueprintAssignable)
	FOnAsyncGetActorsOfClass OnAsyncGetActorsOfClassCompleted;

};

