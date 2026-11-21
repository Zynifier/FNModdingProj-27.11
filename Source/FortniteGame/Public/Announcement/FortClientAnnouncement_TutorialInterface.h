// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "FortClientAnnouncement_TutorialInterface.generated.h"

class UObject;

UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UFortClientAnnouncement_TutorialInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortClientAnnouncement_TutorialInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void HideTutorialWidget();

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetButtonEnabled(bool bButtonEnabled);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetDetailText(FText NameText);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetHAlign(EHorizontalAlignment HAlign);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetLightboxDisableInputOnly(bool bLightboxDisableInputOnly);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetLightboxEnabled(bool bLightboxEnabled);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetNameText(FText NameText);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetPadding(FMargin Padding);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetSystemText(FText SystemText);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetTitleText(FText NameText);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(UnsafeDuringActorConstruction="true"))
	virtual void SetVAlign(EVerticalAlignment VAlign);

	UFUNCTION(BlueprintCallable, Category="Announcement|Tutorial", meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
	virtual void WaitForContinue(UObject* WorldContextObject, FLatentActionInfo LatentInfo);

};

