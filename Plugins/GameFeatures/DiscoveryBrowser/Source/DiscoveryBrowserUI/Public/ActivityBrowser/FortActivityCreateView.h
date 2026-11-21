// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivityCreateView.generated.h"

class UCommonButtonBase;
enum class EFortInvalidActivityReason : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityCreateView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidCreativeActivityReason() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreativeActivityUpdated();

private:
	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCreateView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Create;

};

