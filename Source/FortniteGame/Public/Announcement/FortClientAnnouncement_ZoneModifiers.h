// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Announcement/FortClientAnnouncement.h"
#include "FortClientAnnouncement_ZoneModifiers.generated.h"

class UFortGameplayModifierItemDefinition;

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData_ZoneModifiers : public FFortClientAnnouncementData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortClientAnnouncementData_ZoneModifiers")
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> Modifiers;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_ZoneModifiers : public AFortClientAnnouncement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Announcement|ZoneModifiers", meta=(ExposeOnSpawn="TRUE"))
	float DisplayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Announcement|ZoneModifiers", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_ZoneModifiers ModifiersData;

};

