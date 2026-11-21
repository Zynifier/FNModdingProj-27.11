// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortArrayElementPositionEnum.h"
#include "FortObjectArray.h"
#include "FortCreativeIndexedObjectRegisterComponent.generated.h"

class UObject;
enum class EFortArrayElementPosition : uint8;
enum class EFortNetworkScope : uint8;
enum class EIndexObjectRegisterLogType : uint8;

UENUM(BlueprintType)
enum class EIndexObjectRegisterLogType : uint8
{
	Off = 0,
	On = 1,
	Verbose = 2,
};

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortCreativeIndexedObjectRegisterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TArray<FFortObjectArray>& GetAllRegisteredObjects() const;

	UFUNCTION(BlueprintPure)
	int32 GetIndexForObject(UObject* Object) const;

	UFUNCTION(BlueprintCallable)
	void GetRegisterAtIndex(int32 Index, bool& bIsValid, FFortObjectArray& Register);

	UFUNCTION(BlueprintCallable)
	UObject* GetRegisteredObject(EFortArrayElementPosition Element = EFortArrayElementPosition::First, int32 Index = 0);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
	void PrintRegister(const UObject* WorldContextObject, const FString& PrefixText) const;

	UFUNCTION(BlueprintCallable)
	void RemoveEmptyIndicesFromEnd();

	UFUNCTION(BlueprintCallable)
	void SetDebugLogging(EIndexObjectRegisterLogType NewLogType, EFortNetworkScope NewLogScope);

protected:
	UFUNCTION(BlueprintCallable)
	bool AddObjectToIndex(UPARAM(ref) TArray<FFortObjectArray>& RegisterArray, UObject* Item, int32 Index);

	UFUNCTION(BlueprintCallable)
	void RemoveObjectFromIndex(UPARAM(ref) TArray<FFortObjectArray>& RegisterArray, UObject* Item, bool& WasRemoved, int32& RemovedIndex, int32 Index = -1);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default", meta=(ExposeOnSpawn="TRUE"))
	FGameplayTag RegisterTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TMap<UObject*, int32> ObjectIndexMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TArray<FFortObjectArray> ObjectList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TArray<FFortObjectArray> ObjectsAddedCache;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TArray<FFortObjectArray> ObjectsRemovedCache;

};

