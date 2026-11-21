// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "CurieTypes.h"
#include "CurieHandlers.generated.h"

UENUM()
enum class ECurieHandlerBehavior : uint8
{
	Handler_Add = 0,
	Handler_Replace = 1,
};

UENUM()
enum class ECurieHandlerPriority : uint8
{
	Priority_1 = 1,
	Priority_2 = 2,
	Priority_3 = 3,
	Priority_4 = 4,
	Priority_5 = 5,
	Priority_6 = 6,
	Priority_7 = 7,
	Priority_8 = 8,
	Priority_9 = 9,
	Priority_10 = 10,
	Priority_Default = 11,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UCurieElementAllocationHandler : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class CURIE_API UCurieElementAttachConditionHandler : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerPriority HandlerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Handler", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class CURIE_API UCurieElementAttachHandler : public UCurieElementGameplayEffectOwner
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerPriority HandlerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerBehavior HandlerBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Handler", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

	UPROPERTY(EditDefaultsOnly, Category="Curie Attachment")
	TArray<FCurieEffectContainer> OnBeginAttachmentEffects;

	UPROPERTY(EditDefaultsOnly, Category="Curie Attachment")
	TArray<FCurieEffectContainer> OngoingAttachmentEffects;

	UPROPERTY(EditDefaultsOnly, Category="Curie Attachment")
	TArray<FCurieEffectContainer> OnEndAttachmentEffects;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class CURIE_API UCurieElementInteractWithContainerHandler : public UCurieElementGameplayEffectOwner
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerPriority HandlerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerBehavior HandlerBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Handler", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

	UPROPERTY(EditDefaultsOnly, Category="Curie Interaction")
	TArray<FCurieEffectContainer> OnInstantInteractionEffects;

	UPROPERTY(EditDefaultsOnly, Category="Curie Interaction")
	TArray<FCurieEffectContainer> OnBeginInteractionEffects;

	UPROPERTY(EditDefaultsOnly, Category="Curie Interaction")
	TArray<FCurieEffectContainer> OngoingInteractionEffects;

	UPROPERTY(EditDefaultsOnly, Category="Curie Interaction")
	TArray<FCurieEffectContainer> OnEndInteractionEffects;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class CURIE_API UCurieElementInteractWithElementHandler : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerPriority HandlerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerBehavior HandlerBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Handler", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class CURIE_API UCurieElementInteractWithMaterialHandler : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerPriority HandlerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Handler")
	ECurieHandlerBehavior HandlerBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Handler", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

};

