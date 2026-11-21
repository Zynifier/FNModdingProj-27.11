// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "FortAthenaTutorialHUDContainer.generated.h"

class AFortAthenaTutorialManager;
class UFortAthenaTutorialHUD;
class UFortAthenaTutorialScreen;
class UFortAthenaTutorialScreenData;
class UOverlay;
class UUserWidget;

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialHUDContainer : public UBacchusHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaTutorialScreen> CurrentScreen;

	UPROPERTY()
	TObjectPtr<AFortAthenaTutorialManager> TutorialManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaTutorialHUD> TutorialHUD;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHUDContainer")
	TSoftClassPtr<UUserWidget> TutorialHUDWidgetSoftClass;

	UPROPERTY(EditAnywhere, Export, Category="FortAthenaTutorialHUDContainer", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_TutorialHUD;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHUDContainer")
	TObjectPtr<UFortAthenaTutorialScreenData> TutorialScreenData;

	UPROPERTY(Transient)
	int32 CurrentTutorialStep;

	UPROPERTY(Transient)
	int32 CurrentTutorialSubstep;

};

