// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Creative/Components/MinimapComponent/CreativeMinimapComponentIconList.h"
#include "UI/FortMiniMapComponent.h"
#include "CreativeMiniMapComponent.generated.h"

class UCreativeMinimapComponentIconList;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTexture2D;
enum class ECreativeMinimapComponentIconColorType : uint8;

USTRUCT(BlueprintType)
struct FCreativeMiniMapComponentIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mini Map Component")
	int32 IconIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mini Map Component")
	TObjectPtr<UTexture2D> IconTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mini Map Component")
	FName IconTextureMaterialParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mini Map Component")
	ECreativeMinimapComponentIconColorType IconColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mini Map Component")
	FLinearColor IconLinearColor;

};

USTRUCT(BlueprintType)
struct FFortMiniMapIndicatorTextProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FSlateFontInfo DisplayTextFont;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FLinearColor DisplayTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FVector2D DisplayTextOffset;

};

UCLASS(HideCategories=("Trigger", "VisibleDistance", "Trigger"))
class UCreativeMiniMapComponent : public UFortMiniMapComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIconDataReplicated);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ApplyColorOverridesToMaterial(const ECreativeMinimapComponentIconColorType Color) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ApplyIconTextureOverridesToMaterial(const FName ParameterName, UTexture2D* Icon) const;

	UFUNCTION(BlueprintPure)
	void ApplyLinearColorOverridesToMaterial(const FLinearColor& Color) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ApplyScalarOverridesToMaterial(const FName ParameterName, const float Value) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ApplyVectorOverridesToMaterial(const FName ParameterName, const FLinearColor Value) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetIndicatorIconColor(const FLinearColor& IndicatorIconColor);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIndicatorText(const FText& IndicatorText);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetIndicatorTextColor(const FLinearColor& IndicatorTextColor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetIndicatorTextOffset(const FVector2D& IndicatorTextOffset);

	UPROPERTY(BlueprintAssignable)
	FOnIconDataReplicated OnIconDataReplicatedEvent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Mini Map Data")
	FFortMiniMapIndicatorTextProperties IndicatorTextProperties;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_IconData, Category="CreativeMiniMapComponent")
	FCreativeMiniMapComponentIconData IconData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeMiniMapComponent")
	TObjectPtr<UCreativeMinimapComponentIconList> IconList;

private:
	UFUNCTION()
	void OnRep_IconData();

	UPROPERTY()
	TArray<TObjectPtr<UMaterialInstanceDynamic>> LoadedMIDs;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> LoadedMaterialInterface;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CurrentMID;

};

