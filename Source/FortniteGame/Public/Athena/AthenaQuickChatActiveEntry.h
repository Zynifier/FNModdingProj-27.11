// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "Athena/FortPlayerStateAthena.h"
#include "AthenaQuickChatActiveEntry.generated.h"

class UAthenaEmojiItemDefinition;
class UAthenaQuickChatBank;
class UObject;

UENUM()
enum class EAthenaQuickChatFilteringType : uint8
{
	// There is no filter, always show this item

	AlwaysVisible = 0,
	// Concerned with the active building material type, hide option if not in building mode

	ActiveMaterial = 1,
	// Concerned with a pickup in front of the player, hide option if no pickups are present in front of the player

	FacingPickup = 2,
	// Concerned with the active hotbar item, hide option if in building mode or the harvesting tool is active

	ActiveHotbarItem = 3,
	// Concerned with the active hotbar item, hide option if in building mode or the harvesting tool is active, or if the active item doesn't use ammo

	ActiveHotbarItemAmmo = 4,
	// Prefer a pickup in front of us, but failing that a hotbar item will do

	FacingPickupOrActiveHotbarItem = 5,
	// Display if we don't have a weapon equipped that requires ammo

	NoWeaponEquippedRequiringAmmo = 6,
	// Display if we have a weapon equipped, with the matching ammo tag

	WeaponEquippedOfAmmoType = 7,
};

USTRUCT()
struct FAthenaQuickChatActiveEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<UAthenaQuickChatBank> Bank;

	UPROPERTY()
	TWeakObjectPtr<UObject> ContextObject;

	UPROPERTY()
	int16 ContextValue;

	UPROPERTY()
	int8 Index;

};

USTRUCT()
struct FAthenaQuickChatLeafEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry", meta=(MultiLine="TRUE"))
	FText Label;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry", meta=(MultiLine="TRUE"))
	FText FullChatMessage;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	FSlateBrush Brush;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	bool bPopulateBrushFromContextObject;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	EAthenaQuickChatFilteringType FilterType;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	TObjectPtr<UAthenaEmojiItemDefinition> EmojiItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	ETeamMemberState TeamCommType;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickChatLeafEntry")
	FGameplayTag OptionGameplayTag;

};

