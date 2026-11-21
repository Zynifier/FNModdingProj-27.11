// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "FortFlagTileButton.generated.h"

class UFortFlagImage;
class UFortFlagObject;
class UImage;
class UTexture2D;

UCLASS(BlueprintType)
class UFortFlagObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortFlagObject")
	FString RegionId;

	UPROPERTY(BlueprintReadOnly, Category="FortFlagObject")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortFlagObject")
	TSoftObjectPtr<UTexture2D> FlagTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortFlagObject")
	bool bSelected;

};

UCLASS(BlueprintType, Blueprintable)
class UFortFlagTileButton : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Display Data")
	FName IconParamName;

	UPROPERTY(Transient)
	TObjectPtr<UFortFlagObject> SourceObject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> FlagImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Active;

};

