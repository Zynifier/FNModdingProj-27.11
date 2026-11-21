// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Showdown/FortShowdownDivisionEventView.h"
#include "FortDivisionLobbyPanel.generated.h"

class UCommonButtonLegacy;
class UFortLazyImage;

UCLASS(Abstract)
class UFortDivisionLobbyPanel : public UFortShowdownDivisionEventView
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortDivisionLobbyPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle EventDetailsAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_CurrentDivisionFancy;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_CurrentDivisionPlain;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_NextDivision;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EventDetails;

};

