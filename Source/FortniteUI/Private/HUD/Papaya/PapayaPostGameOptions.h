// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "PapayaPostGameOptions.generated.h"

class UFortPostGameMenuListView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UPapayaPostGameOptions : public UFortPostGameScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPostGameMenuListView> ListView_PostGameMenu;

};

