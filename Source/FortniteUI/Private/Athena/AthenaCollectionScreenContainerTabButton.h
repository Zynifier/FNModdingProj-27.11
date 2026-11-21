// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "AthenaCollectionScreenContainerTabButton.generated.h"

class UCommonLazyImage;
class UObject;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionScreenContainerTabButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show Bang"))
	void BP_ShowBang(bool bShow);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Set Icon"))
	void SetIcon(TSoftObjectPtr<UObject> LazyObject);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenContainerTabButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

private:
	UPROPERTY()
	FString CollectionType;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

	UPROPERTY()
	FText TabTitle;

	UPROPERTY()
	FGameplayTagContainer CategoryTags;

};

