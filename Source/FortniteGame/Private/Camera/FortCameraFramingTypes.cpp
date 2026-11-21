// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortCameraFramingTypes.h"

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateActorBoundsForCameraFraming(const AActor* Actor, bool bIgnoreHiddenOrNotVisibleComponents, bool bIncludePSCs)
{
	return FFortUICameraFrameTargetBounds();
}

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateCharacterBoundsForCameraFraming(const AFortPlayerPawn* PlayerPawn)
{
	return FFortUICameraFrameTargetBounds();
}

FFortUICameraFrameTargetSettings UFortUICameraFramingFunctionLibrary::CalculateCharacterBoundsForZoomedCameraFraming(const AFortPlayerPawn* PlayerPawn)
{
	return FFortUICameraFrameTargetSettings();
}

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateCharacterCapsuleForCameraFraming(const ACharacter* Character)
{
	return FFortUICameraFrameTargetBounds();
}

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateComponentBoundsForCameraFraming(USceneComponent* ParentComponent, const bool bIncludePSCs)
{
	return FFortUICameraFrameTargetBounds();
}

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateComponentSetBoundsForCameraFraming(const TSet<USceneComponent*>& Components, bool bIgnoreHiddenOrNotVisibleComponents, bool bIncludePSCs)
{
	return FFortUICameraFrameTargetBounds();
}

FFortUICameraFrameTargetBounds UFortUICameraFramingFunctionLibrary::CalculateVisibleItemDefinitionBoundsForCameraFraming(const UAthenaCharacterPartItemDefinition* ItemDefinition)
{
	return FFortUICameraFrameTargetBounds();
}
