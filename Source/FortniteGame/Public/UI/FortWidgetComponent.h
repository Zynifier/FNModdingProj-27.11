// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Math/MathFwd.h"
#include "FortWidgetComponent.generated.h"

enum class EClampToScreenDirection : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Mobility", "Trigger"), ClassGroup=("UserInterface"), meta=(BlueprintSpawnableComponent))
class UFortWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClampStateChanged, EClampToScreenDirection, ClampToScreenDirection);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="User Interface")
	bool bClampProjectedLocalPositionToViewport;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="User Interface")
	FVector2D PreClampedLocalPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="User Interface")
	float ClampPaddingTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="User Interface")
	float ClampPaddingBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="User Interface")
	float ClampPaddingLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="User Interface")
	float ClampPaddingRight;

	UPROPERTY(BlueprintAssignable)
	FOnClampStateChanged OnClampStateChangedEvent;

};

