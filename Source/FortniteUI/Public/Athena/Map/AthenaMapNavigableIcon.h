// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/MathFwd.h"
#include "AthenaMapNavigableIcon.generated.h"

class UImage;
class UTexture2D;

UCLASS(Abstract, MinimalAPI, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMapNavigableIcon : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FORTNITEUI_API bool IsIconHovered() const;

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API bool IsIconSelected() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnChallengeIconOverriden(const UTexture2D* Icon);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnChallengeReset();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnChallengeSet(bool bIsComplete, bool bIsLocked, bool bHasIconOverride, float Progress, bool bShouldShowBang, bool bIsPinned, bool bChallengeSelected);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnChangeBangVisibility(bool bShouldShow);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnHovered(bool bUserInteraction);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSelected(bool bUserInteraction);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSetHasLocation(bool bHasLocation);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSetIsInGame(bool bIsInGame);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnUnhovered(bool bUserInteraction);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnUnselected(bool bUserInteraction);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapNavigableIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(EditDefaultsOnly, Category="AthenaMapNavigableIcon")
	FVector2D AnchorPoint;

};

