// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonButtonBase.h"
#include "Context/FortSocialPanelContext.h"
#include "FortSidebarSpecialNavWidgetBase.generated.h"

class UFortSidebarOnboardTooltipWidget;
class UFortSidebarSpecialNavButtonBase;
enum class EFortSidebarSpecialNavType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarSpecialNavButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarSpecialNavWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	EFortSidebarSpecialNavType GetNavType();

protected:
	UPROPERTY(EditAnywhere, Category="Sidebar", meta=(DisplayName="Go To Panel"))
	EFortSidebarSpecialNavType NavType;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSidebarSpecialNavWidgetBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UFortSidebarSpecialNavButtonBase* Button;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	UFortSidebarOnboardTooltipWidget* AvailableTooltip;

};

