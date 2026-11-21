// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Frontend/Spatial/Customization/SpatialCustomizationRoomData.h"
#include "SpatialCustomizationChoice.generated.h"

class UAthenaRewardEventGraph;
class UFortLazyImage;
class UImage;
enum class ESpatialCustomizationCategoryState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpatialCustomizationChoice : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupChoice(ESpatialCustomizationCategoryState State, FLinearColor Color);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationChoice", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_ItemIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Locked;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Owned;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationChoice")
	FName ColorChoiceDivetParam;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationChoice")
	FName NullColorDivetParam;

	UPROPERTY(EditInstanceOnly, Category="AthenaSpatialCustomizationChoice")
	FVector2D Size;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaSpatialCustomizationChoice")
	TObjectPtr<UAthenaRewardEventGraph> DesignTimeGraph;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaSpatialCustomizationChoice")
	FGameplayTag DesignTimePreviewRewardNode;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaSpatialCustomizationChoice")
	ESpatialCustomizationCategoryState DesignerPreviewState;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaSpatialCustomizationChoice")
	FLinearColor DesignerPreviewStateColor;
#endif

	UPROPERTY()
	FGameplayTag ChoiceTag;

};

