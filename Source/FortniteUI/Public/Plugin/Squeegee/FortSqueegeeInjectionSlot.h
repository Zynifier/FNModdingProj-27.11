// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "FortSqueegeeInjectionSlot.generated.h"

class UFortActivityViewModel;
class UFortGameActivity;
class UFortSqueegeeWidget;
class UNamedSlot;

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortSqueegeeWidgetInjectionSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSqueegeeWidgetInjectionSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void ShowActivityData(UFortGameActivity* GameActivity);

	UFUNCTION(BlueprintCallable)
	void ShowActivityDataFromViewModel(UFortActivityViewModel* GameActivityViewModel);

	UPROPERTY(EditInstanceOnly, Category="FortSqueegeeWidgetInjectionSlot")
	ESqueegeeWidgetInjection DesiredInjection;

	UPROPERTY(EditAnywhere, Category="FortSqueegeeWidgetInjectionSlot")
	FSqueegeeStyleParams StyleParams;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSqueegeeWidgetInjectionSlot", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UNamedSlot> InjectionSlot;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortSqueegeeWidget* InjectedSqueegeeWidget;

};

