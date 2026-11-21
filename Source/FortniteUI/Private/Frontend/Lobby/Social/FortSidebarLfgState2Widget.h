// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "FortSidebarLfgState2Widget.generated.h"

class UCommonButtonBase;
enum class ELfgState : uint8;

UCLASS(meta=(DisableNativeTick))
class UFortSidebarLfgState2Widget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged(const ELfgState NewLfgState, const ESlateVisibility BodyVisibility, const FText& StateText, const FText& StateButton);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSidebarLfgState2Widget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button;

};

