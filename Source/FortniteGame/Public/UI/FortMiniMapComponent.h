// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "Visibility/FortVisibilityComponent.h"
#include "FortMiniMapComponent.generated.h"

class AFortPlayerController;
class UFortMiniMapIndicator;
class UMaterialInstanceDynamic;
class UObject;
class UTexture2D;
class UTexture;

UENUM()
enum class EMiniMapIconParameterDataType : uint8
{
	/** Used when unset */
	None = 0,
	/** Represents data used to modify a given scalar parameter of a dynamic material instance */
	Scalar = 1,
	/** Represents data used to modify a given vector parameter of a dynamic material instance */
	Vector = 2,
	/** Represents data used to modify a given texture parameter of a dynamic material instance */
	Texture = 3,
};

USTRUCT(BlueprintType)
struct FFortMiniMapIconMaterialParameterData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EMiniMapIconParameterDataType DataType;

	UPROPERTY()
	FName Name;

	UPROPERTY()
	float Scalar;

	UPROPERTY()
	FLinearColor Vector;

	UPROPERTY()
	TObjectPtr<UTexture> Texture;

};

USTRUCT(BlueprintType)
struct FFortMiniMapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TObjectPtr<UObject> MiniMapIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FVector2D IconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bUseIconSize : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FVector2D IconMaterialSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bIsVisible : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bIsVisibleOnMiniMap : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bIsVisibleOnMap : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bIsVisibilityBasedOnTeam : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bShowVerticalOffset : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bShowFarOffIndicator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bDisplayIconEvenOnFogOfWar : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bAllowLocalOverrides : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 bUseTeamAffiliationColors : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMapData")
	TEnumAsByte<EFortMinimapLayer> DrawLayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data", meta=(EditCondition="!bUseTeamAffiliationColors"))
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data", meta=(EditCondition="bUseTeamAffiliationColors"))
	FLinearColor FriendColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data", meta=(EditCondition="bUseTeamAffiliationColors"))
	FLinearColor EnemyColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data", meta=(EditCondition="bUseTeamAffiliationColors"))
	FLinearColor NeutralColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FLinearColor PulseColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	float ColorPulsesPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	float SizePulsesPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	float ViewableDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	uint8 Team;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap Data")
	TArray<FFortMiniMapIconMaterialParameterData> MiniMapIconMaterialParameterDataList;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "VisibleDistance", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortMiniMapComponent : public UFortVisibilityComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UMaterialInstanceDynamic* GetDynamicMaterial();

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void OverrideLocalMiniMapIcon(UTexture2D* MiniMapIcon);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void OverrideLocalMiniMapIndicatorIsVisible(bool bVisible);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	virtual void SetMiniMapIcon(UObject* MiniMapIcon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIconColor(FLinearColor InColor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIconColorPulsesPerSecond(float ColorPulsesPerSecond);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetMiniMapIconMaterialScalarParameterValue(const FName ParameterName, const float Value);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetMiniMapIconMaterialTextureParameterValue(const FName ParameterName, UTexture* Value);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetMiniMapIconMaterialVectorParameterValue(const FName ParameterName, const FLinearColor Value);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIconPulseColor(FLinearColor PulseColor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	virtual void SetMiniMapIconScale(const FVector2D& IconScale);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIconSizePulsesPerSecond(float SizePulsesPerSecond);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIndicatorIsVisible(bool bVisible = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIndicatorIsVisibleOnMap(bool bVisibleOnMap = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIndicatorIsVisibleOnMiniMap(bool bVisibleOnMiniMap = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapIndicatorTeam(uint8 Team);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetMiniMapLocationOffset(const FVector& LocationOffset);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data", meta=(ClampMax="1000000", ClampMin="0.0"))
	void SetMiniMapViewableDistance(float ViewDistance = 4000.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap Data")
	void SetupMiniMapComponent(UTexture2D* MiniMapIcon, FLinearColor IconColor = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000), FLinearColor PulseColor = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000), float ColorPulsesPerSecond = 0.000000f, float SizePulsesPerSecond = 0.000000f);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="MiniMap Data")
	bool IsVisibleToPlayer(const AFortPlayerController* PC) const;

	UFUNCTION()
	virtual void OnRep_MiniMapData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_MiniMapData, Category="Mini Map Data")
	FFortMiniMapData MiniMapData;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> LocalMinimapIconOverride;

	UPROPERTY()
	TWeakObjectPtr<UFortMiniMapIndicator> MiniMapIndicator;

	UPROPERTY(EditDefaultsOnly, Category="FortMiniMapComponent")
	TSubclassOf<UFortMiniMapIndicator> MinimapIndicatorClass;

};

