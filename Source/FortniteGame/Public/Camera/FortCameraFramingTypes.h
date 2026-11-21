// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortCameraFramingTypes.generated.h"

class AActor;
class ACharacter;
class AFortPlayerPawn;
class IFortUICameraFrameTargetInterface;
class UAthenaCharacterPartItemDefinition;
class USceneComponent;

UENUM(BlueprintType)
enum class EFortUICameraFrameTargetBoundingBehavior : uint8
{
	NoBounds = 0,
	AllBounds = 1,
	TopBoundOnly = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FFortOnCameraFrameTargetSettingsChangedDelegate, TScriptInterface<IFortUICameraFrameTargetInterface>, Object);

USTRUCT(BlueprintType)
struct FFortUICameraFrameTargetBounds
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUICameraFrameTargetBounds")
	FVector Origin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUICameraFrameTargetBounds")
	float CylinderHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUICameraFrameTargetBounds")
	float CylinderRadius;

};

USTRUCT(BlueprintType)
struct FFortUICameraFrameTargetSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortUICameraFrameTargetSettings")
	FVector FocusPointToCenter;

	UPROPERTY(BlueprintReadWrite, Category="FortUICameraFrameTargetSettings")
	EFortUICameraFrameTargetBoundingBehavior BoundingBehavior;

	UPROPERTY(BlueprintReadWrite, Category="FortUICameraFrameTargetSettings")
	FFortUICameraFrameTargetBounds BoundsToFrame;

	UPROPERTY(BlueprintReadWrite, Category="FortUICameraFrameTargetSettings")
	FRotator FocusObjectRotation;

};

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortItemPreviewBoundsInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortItemPreviewBoundsInterface
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortUICameraFrameInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortUICameraFrameInterface
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortUICameraFrameTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortUICameraFrameTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FFortUICameraFrameTargetSettings GetZoomedInCameraFramingSettings();

	UFUNCTION(BlueprintNativeEvent)
	FFortUICameraFrameTargetSettings GetZoomedOutCameraFramingSettings();

	UFUNCTION(BlueprintNativeEvent)
	void SetFrameTargetSettingsChangedDelegate(const FFortOnCameraFrameTargetSettingsChangedDelegate& Delegate);

};

UCLASS()
class UFortUICameraFramingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateActorBoundsForCameraFraming(const AActor* Actor, bool bIgnoreHiddenOrNotVisibleComponents = true, bool bIncludePSCs = true);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateCharacterBoundsForCameraFraming(const AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetSettings CalculateCharacterBoundsForZoomedCameraFraming(const AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateCharacterCapsuleForCameraFraming(const ACharacter* Character);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateComponentBoundsForCameraFraming(USceneComponent* ParentComponent, const bool bIncludePSCs = true);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateComponentSetBoundsForCameraFraming(const TSet<USceneComponent*>& Components, bool bIgnoreHiddenOrNotVisibleComponents = true, bool bIncludePSCs = true);

	UFUNCTION(BlueprintCallable)
	static FFortUICameraFrameTargetBounds CalculateVisibleItemDefinitionBoundsForCameraFraming(const UAthenaCharacterPartItemDefinition* ItemDefinition);

};

UINTERFACE(MinimalAPI, NotBlueprintable)
class UFortUICameraPositionTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortUICameraPositionTargetInterface
{
	GENERATED_BODY()

};

