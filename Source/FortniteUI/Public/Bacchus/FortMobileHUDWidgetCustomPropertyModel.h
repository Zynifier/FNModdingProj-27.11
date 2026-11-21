// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortMobileHUDWidgetCustomPropertyModel.generated.h"

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UFortMobileHUDWidgetCustomPropertyModel : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel")
	bool bIsVisibleToTheUser;

	UPROPERTY(VisibleAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel")
	FString PropertyDevName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel")
	FText PropertyDisplayName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel", meta=(Categories="HUDLayout.Property"))
	FGameplayTag PropertyTag;

};

