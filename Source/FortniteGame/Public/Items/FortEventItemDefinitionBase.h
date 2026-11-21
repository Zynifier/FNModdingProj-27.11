// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortEventItemDefinitionBase.generated.h"

UCLASS(Abstract, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level"))
class UFortEventItemDefinitionBase : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="Event", meta=(CallInEditor="true"))
	void CreateCalendarPayload();

protected:
	UPROPERTY(EditAnywhere, Category="Event")
	int32 EventPriority;

	UPROPERTY(EditAnywhere, Category="Event")
	bool bActivateByDefault;

	UPROPERTY(EditAnywhere, Category="Event")
	FName RequiredEventTag;

	UPROPERTY(EditAnywhere, Category="Event")
	FName DisallowedEventTag;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Event")
	FString CalendarChannelName;
#endif

};

