// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuickHealPriority.generated.h"

UENUM(BlueprintType)
enum class EPriorityInsertion : uint8
{
	AfterReferenceTag = 0,
	BeforeReferenceTag = 1,
};

USTRUCT(BlueprintType)
struct FQuickHealPriority
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuickHealPriority", meta=(Categories="MobileHUD.QuickHealPriority"))
	FGameplayTag PriorityGroupTag;

	UPROPERTY(EditAnywhere, Category="QuickHealPriority", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MinHealth;

	UPROPERTY(EditAnywhere, Category="QuickHealPriority", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category="QuickHealPriority", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MinShields;

	UPROPERTY(EditAnywhere, Category="QuickHealPriority", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MaxShields;

	UPROPERTY(EditAnywhere, Category="QuickHealPriority")
	TArray<FGameplayTag> GameplayTags;

};

USTRUCT(BlueprintType)
struct FQuickHealPrioritySpecifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QuickHealPrioritySpecifier", meta=(Categories="Item.Consumable"))
	FGameplayTag QuickhealItemTag;

	UPROPERTY(EditDefaultsOnly, Category="QuickHealPrioritySpecifier", meta=(Categories="Item.Consumable"))
	FGameplayTag PositionReferenceTag;

	UPROPERTY(EditDefaultsOnly, Category="QuickHealPrioritySpecifier")
	EPriorityInsertion PriorityInsertionPlacement;

	UPROPERTY(EditDefaultsOnly, Category="QuickHealPrioritySpecifier")
	int32 Priority;

};

USTRUCT(BlueprintType)
struct FQuickHealPriorityExtension
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QuickHealPriorityExtension", meta=(Categories="MobileHUD.QuickHealPriority"))
	FGameplayTag QuickhealPriorityGroupTag;

	UPROPERTY(EditDefaultsOnly, Category="QuickHealPriorityExtension")
	TArray<FQuickHealPrioritySpecifier> QuickhealItemPrioritySpecifiers;

};

