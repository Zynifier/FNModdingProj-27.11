// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "FortLegacySlateBridgeWidget.generated.h"

enum class EFortLegacySlateWidget : uint8;

UENUM(BlueprintType)
enum class EFortLegacySlateWidget : uint8
{
	None = 0,
	Minimap = 1,
	MAX = 2 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnCloseLegacyWidget);

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI", DisplayName="Fort Slate Widget"))
class UFortLegacySlateBridgeWidget : public UNativeWidgetHost
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortSlateWidget")
	void SetOnCloseHandler(const FOnCloseLegacyWidget& OnCloseHandler);

	UFUNCTION(BlueprintCallable, Category="FortSlateWidget")
	void UpdateSlateWidget(EFortLegacySlateWidget SlateWidgetType);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSlateWidget", meta=(ExposeOnSpawn="true"))
	EFortLegacySlateWidget ContainedWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSlateWidget", meta=(ClampMax="4.0", ClampMin="0.0", DisplayName="DPI Scale Factor", ExposeOnSpawn="true"))
	float DPIScaleFactor;

private:
	UPROPERTY(Transient)
	FOnCloseLegacyWidget OnClose;

};

