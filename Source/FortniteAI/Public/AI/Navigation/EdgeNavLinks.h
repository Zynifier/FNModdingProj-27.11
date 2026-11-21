// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "NavLinkRenderingComponent.h"
#include "Navigation/NavLinkProxy.h"
#include "EdgeNavLinks.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("SimpleLink", "SmartLink", "Rendering", "Actor", "Input"), AutoCollapseCategories=("SmartLink", "Actor"))
class AEdgeNavLinks : public ANavLinkProxy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="EdgeLink", meta=(ClampMin="1", UIMin="1"))
	float DistanceBetweenLinks;

	UPROPERTY(EditAnywhere, Category="EdgeLink", meta=(MakeEditWidget))
	FVector Start;

	UPROPERTY(EditAnywhere, Category="EdgeLink", meta=(MakeEditWidget))
	FVector End;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EdgeLink", meta=(ClampMin="50", UIMin="50"))
	float SnapRadius;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EdgeLink", meta=(ClampMin="50", UIMin="50"))
	float SnapHeight;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EdgeLink", meta=(ClampMin="0", UIMin="0"))
	float LinkProjectionHeight;

	UPROPERTY()
	float RightLinkForwardOffset;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EdgeLink")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	UPROPERTY(EditAnywhere, Category="EdgeLink")
	uint8 bManualAdjustment : 1;

};

UCLASS(HideCategories=("Object", "Mobility", "VirtualTexture", "Trigger"))
class UEdgeNavLinksRenderingComponent : public UNavLinkRenderingComponent
{
	GENERATED_BODY()

};

