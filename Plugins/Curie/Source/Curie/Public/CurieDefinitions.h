// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "CurieDefinitions.generated.h"

class UCurieElementAllocationHandler;
class UCurieElementAttachConditionHandler;
class UCurieElementAttachHandler;
class UCurieElementInteractWithContainerHandler;
class UCurieElementInteractWithElementHandler;
class UCurieElementInteractWithMaterialHandler;
class UCurieEntityStateBehavior;

USTRUCT()
struct CURIE_API FCurieElementDefinitionBase : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, NoClear, Category="CurieElementDefinitionBase")
	TSubclassOf<UCurieElementAllocationHandler> ElementAllocationHandler;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	TArray<TSubclassOf<UCurieElementAttachHandler>> ElementAttachHandlers;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	TSubclassOf<UCurieElementAttachConditionHandler> ElementAttachConditionHandler;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	TArray<TSubclassOf<UCurieElementInteractWithElementHandler>> ElementInteractHandlers;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	TArray<TSubclassOf<UCurieElementInteractWithMaterialHandler>> ElementMaterialInteractHandlers;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	TArray<TSubclassOf<UCurieElementInteractWithContainerHandler>> ElementContainerInteractHandlers;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase", meta=(Categories="CurieElement"))
	FGameplayTagContainer ElementalImmunities;

	UPROPERTY(EditDefaultsOnly, Category="CurieElementDefinitionBase")
	uint8 bIsEnabled : 1;

};

USTRUCT()
struct CURIE_API FCurieEntityStateDefinitionBase : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Curie")
	TSubclassOf<UCurieEntityStateBehavior> StateBehaviorClass;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	uint8 bIsEnabled : 1;

};

USTRUCT()
struct CURIE_API FCurieMaterialDefinitionBase : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="CurieElement"))
	FGameplayTagContainer ElementalImmunities;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="CurieElement"))
	FGameplayTagContainer ElementAttachmentImmunities;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="CurieElement"))
	FGameplayTagContainer ElementsAllowedWhenCannotBeDamaged;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="CurieMaterialProperty"))
	FGameplayTagContainer MaterialProperties;

};

