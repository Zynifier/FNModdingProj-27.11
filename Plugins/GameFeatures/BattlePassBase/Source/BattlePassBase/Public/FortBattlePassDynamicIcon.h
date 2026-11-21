// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortBattlePassDynamicIcon.generated.h"

class UFortLazyImage;
class UObject;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassDynamicIcon : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBattlePassDynamicIcon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassInfoUpdated(const bool bOwnsBattlePass) const;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassDynamicIcon", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> BattlePassDefaultIcon;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassDynamicIcon", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> BattlePassOwnedIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_BattlePassIcon;

};

