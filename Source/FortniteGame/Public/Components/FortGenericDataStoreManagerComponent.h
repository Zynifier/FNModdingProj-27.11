// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortGenericDataStoreManagerComponent.generated.h"

class UObject;

USTRUCT()
struct FFortGenericDataStoreMapWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FName, TObjectPtr<UObject>> NamedStoreMap;

};

UCLASS()
class UFortGenericDataStoreManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Data Store", meta=(AutoCreateRefTerm="StoreName,ClassType", DeterminesOutputType="ClassType"))
	UObject* AddNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType);

	UFUNCTION(BlueprintPure, Category="Data Store", meta=(AutoCreateRefTerm="StoreName,ClassType", DeterminesOutputType="ClassType"))
	UObject* GetNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType) const;

	UFUNCTION(BlueprintCallable, Category="Data Store", meta=(AutoCreateRefTerm="StoreName,ClassType"))
	bool RemoveNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType);

private:
	UPROPERTY()
	TMap<TSubclassOf<UObject>, FFortGenericDataStoreMapWrapper> ClassToNameMapping;

};

