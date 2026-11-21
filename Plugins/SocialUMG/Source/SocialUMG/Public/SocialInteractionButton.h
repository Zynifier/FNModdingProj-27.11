// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "SocialInteractionButton.generated.h"

class UBorder;
class UCommonTextBlock;

UCLASS(Abstract)
class SOCIALUMG_API USocialInteractionButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	FName GetInteractionName() const;

	UFUNCTION(BlueprintPure)
	bool IsPlatformOnlyFriend() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInteractionSet();

	UPROPERTY(EditAnywhere, Category="SocialInteractionButton")
	FLinearColor DefaultIndicatorColor;

	UPROPERTY(EditAnywhere, Category="SocialInteractionButton")
	FLinearColor AlertingIndicatorColor;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="SocialInteractionButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InteractionName;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialInteractionButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_InteractionIndicator;

};

