// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "FortPartyStatusIcon.generated.h"

class UFortSocialUser;
class UMaterialInterface;

UCLASS()
class FORTNITEUI_API UFortPartyStatusIcon : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetImageColorAndOpacity(const FSlateColor& InColorAndOpacity);

	UFUNCTION(BlueprintCallable)
	void SetPlayerNetIdFromFortUser(UFortSocialUser* InSocialUser);

private:
	UPROPERTY(EditAnywhere, Category="FortPartyStatusIcon")
	FVector2D DesiredSize;

	UPROPERTY(EditAnywhere, Category="FortPartyStatusIcon")
	FSlateColor ImageColorAndOpacity;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> PartyStatusMaterial;

	UPROPERTY(Transient)
	FSlateBrush StatusBrush;

};

