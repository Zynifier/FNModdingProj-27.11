// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HabaneroIntroModal.generated.h"

class UCommonButtonBase;

UCLASS()
class FORTNITEGAME_API UHabaneroIntroModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Habanero")
	bool GetCanEngageHabanero() const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="HabaneroIntroModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Engage;

	UPROPERTY(BlueprintReadOnly, Export, Category="HabaneroIntroModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Dismiss;

	UPROPERTY(BlueprintReadOnly, Export, Category="HabaneroIntroModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseMobile;

};

