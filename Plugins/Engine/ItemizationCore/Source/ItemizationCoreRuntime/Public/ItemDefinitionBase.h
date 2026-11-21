// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDefinitionBase.generated.h"

class UItemAttribute;
class UItemComponentBase;

USTRUCT()
struct FItemComponentContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Export, Category="Default", meta=(EditInline="true"))
	TArray<TObjectPtr<UItemComponentBase>> Components;

};

UCLASS(Abstract, BlueprintType)
class ITEMIZATIONCORERUNTIME_API UItemDefinitionBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	//~ End UObject Interface

	UFUNCTION(BlueprintPure, Category="Item Definition")
	virtual const UItemComponentBase* GetItemComponentByClass(const TSubclassOf<UItemComponentBase> ItemComponentClass) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Item Definition")
	FItemComponentContainer ComponentContainer;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UItemComponentBase>> CachedComponentList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<UItemComponentBase>, TObjectPtr<UItemComponentBase>> CachedComponentMap;

	UPROPERTY(Transient)
	TSet<TSubclassOf<UItemAttribute>> CachedAttributeSet;

};

