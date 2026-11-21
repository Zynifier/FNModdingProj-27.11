// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ClassSelectorTeamTiles.generated.h"

class UClassSelectorTeamTile;
class UUniformGridPanel;

UCLASS(meta=(DisableNativeTick))
class UClassSelectorTeamTiles : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UClassSelectorTeamTile>> TeamTiles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUniformGridPanel> RootPanel;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTeamTiles")
	TSubclassOf<UClassSelectorTeamTile> EntryClass;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTeamTiles")
	int32 DesignerPreviewEntries;

};

