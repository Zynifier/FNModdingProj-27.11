// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "BuildingTypes.generated.h"

UENUM()
enum EBuildingAttachmentType
{
	// Attaches to a floor

	ATTACH_Floor = 0,
	// Attaches to a wall

	ATTACH_Wall = 1,
	// Attaches to a ceiling

	ATTACH_Ceiling = 2,
	// Attaches to 2 walls

	ATTACH_Corner = 3,
	// Attaches to any valid slot

	ATTACH_All = 4,
	// Attempts to attach to a wall; If a wall is not found, attempts to attach to floors

	ATTACH_WallThenFloor = 5,
	// Attaches to floors or top side of stairs and sloped roofs

	ATTACH_FloorAndStairs = 6,
	// Attaches to ceiling or underside of stairs and sloped roofs

	ATTACH_CeilingAndStairs = 7,
	// Only use when placing from top or underside of stairs does NOT matter (e.g. when replacing the building on place). Traps using this attachment type must have a StairTrap TID.

	ATTACH_StairsBothSides = 8,
	ATTACH_None = 9,
};

UENUM()
namespace EBuildingHighlightType
{
	enum Type
	{
		Primary = 0,
		Interact = 1,
		WillBeDestroyed = 2,
		Quest = 3,
		/** Highlight useful for things that need to draw attention outside the main flow of forced/interact highlights, such as world-based objectives */
		AuxiliaryInterestPoint = 4,
		MAX_None = 5,
	};
}

UENUM(BlueprintType)
namespace EFortBounceType
{
	enum Type
	{
		Hit = 0,
		Interact = 1,
		EditPlaced = 2,
	};
}

UENUM()
enum class EFortBuildingDestroyedReason : uint8
{
	Unknown = 0,
	WeaponDamage = 1,
	LostSupport = 2,
	Edit = 3,
	FireDirect = 4,
	FireIndirect = 5,
};

UENUM(BlueprintType)
namespace EFortBuildingInitializationReason
{
	enum Type
	{
		// Actor was placed in the editor

		StaticallyPlaced = 0,
		// Created at runtime

		Spawned = 1,
		// Replaced an existing building actor

		Replaced = 2,
		// Actor was loaded from a save state

		LoadedFromSave = 3,
		// Actor Was placed by a DynamicBuilder

		DynamicBuilderPlaced = 4,
		// Placed by the placement tool 

		PlacementTool = 5,
		// Placed by the trap tool 

		TrapTool = 6,
		// Always at the end

		None = 7,
	};
}

UENUM(BlueprintType)
namespace EFortBuildingPersistentState
{
	enum Type
	{
		// Building actor is the same as it was

		Default = 0,
		// Building actor is being spawned for the first time in a world

		New = 1,
		// Building actor has finished being constructed

		Constructed = 2,
		// Actor has been destroyed

		Destroyed = 3,
		// Actor has been searched but still exists

		Searched = 4,
		None = 5,
	};
}

UENUM(BlueprintType)
namespace EFortBuildingState
{
	enum Type
	{
		// Player is holding a building primitive shape to place

		Placement = 0,
		// Player is editing an existing building

		EditMode = 1,
		None = 2,
	};
}

UENUM(BlueprintType)
namespace EFortBuildingType
{
	enum Type
	{
		// A simple wall

		Wall = 0,
		// A simple floor

		Floor = 1,
		// Corner mesh that connects walls

		Corner = 2,
		// A decorative item with no collision or physics

		Deco = 3,
		// Decorative piece that can be destroyed

		Prop = 4,
		// Floor with height

		Stairs = 5,
		// Wall with width for roofing

		Roof = 6,
		// Wall taking up entire square

		Pillar = 7,
		// A dynamically spawned item

		SpawnedItem = 8,
		// Lootable container that randomly spawns

		Container = 9,
		// Trap

		Trap = 10,
		// Generic center cell actor

		GenericCenterCellActor = 11,
		// Invalid

		None = 12,
	};
}

UENUM()
namespace EFortConnectivityCubeFace
{
	enum Type
	{
		// Front wall cube face

		Front = 0,
		// Left wall cube face

		Left = 1,
		// Back wall cube face

		Back = 2,
		// Right wall cube face

		Right = 3,
		// Upper floor cube face

		Upper = 4,
		// Lower floor cube face

		Lower = 5,
		MAX = 6,
	};
}

UENUM()
namespace EFortCostInfoTypes
{
	enum Type
	{
		// Placement cost

		Placement = 0,
		// Repair cost

		Repair = 1,
		// Conversion cost

		Conversion = 2,
		// Preview cost of ability we are going to execute

		Ability = 3,
		// No cost info

		None = 4,
	};
}

UENUM()
namespace EFortDecoPlacementQueryResults
{
	enum Type
	{
		// The actor can be added

		CanAdd = 0,
		// The actor is blocked by an existing trap

		ExistingTrap = 1,
		// The actor is blocked by another existing object

		ExistingObject = 2,
		// The actor is obstructed by world geometry or building actors

		Obstructed = 3,
		// Didn't find a valid location to place it

		NoLocation = 4,
		// Can't place on this type of building actor

		WrongType = 5,
		// Can't place on this shape of building actor

		WrongShape = 6,
		// Can't place because someone else is modifying it

		BeingModified = 7,
		// Can't place on another team's buildings

		WrongTeam = 8,
		// Blueprint function returned a custom failure reason

		BlueprintFailure = 9,
		// Placement ability cannot be activated

		AbilityFailure = 10,
		// The actor can only be placed on player-buildable actors

		RequiresPlayerBuildableActor = 11,
		// Player does not have edit permission

		NoEditPermission = 12,
		// Player is in wrong zone to place this type of trap

		WrongZone = 13,
	};
}

UENUM(BlueprintType)
namespace EFortResourceLevel
{
	enum Type
	{
		First = 0,
		Second = 1,
		Third = 2,
		// 4-6 are only for ld-placed buildings

		Fourth = 3,
		Fifth = 4,
		Sixth = 5,
		NumLevels = 6,
		Invalid = 7,
	};
}

UENUM(BlueprintType)
namespace EFortResourceType
{
	enum Type
	{
		Wood = 0,
		Stone = 1,
		Metal = 2,
		Permanite = 3,
		GoldCurrency = 4,
		Ingredient = 5,
		// If adding a resource, please add here and add conversion code to EFortResourceType::ToSurfaceType directly below, if needed

		None = 6,
	};
}

UENUM(BlueprintType)
namespace EFortStructuralGridQueryResults
{
	enum Type
	{
		// The actor can be added

		CanAdd = 0,
		// The actor is blocked by an existing building actor

		ExistingActor = 1,
		// The actor is obstructed by world geometry

		Obstructed = 2,
		// The actor lacks structural support and cannot be placed

		NoStructuralSupport = 3,
		// The actor and/or query is invalid

		InvalidActor = 4,
		// Structure limit has been reached

		ReachedLimit = 5,
		// Player does not have edit permission

		NoEditPermission = 6,
		// Does not match layout requirement pattern

		PatternNotPermittedByLayoutRequirement = 7,
		// Does not match layout requirement resource

		ResourceTypeNotPermittedByLayoutRequirement = 8,
		// Building AT Layout Requirements is disabled

		BuildingAtRequirementsDisabled = 9,
		// Only building within layout requirements is allowed; all other building is disabled.

		BuildingOtherThanRequirementsDisabled = 10,
	};
}

UENUM()
namespace EFortTextureDataSlot
{
	enum Type
	{
		// Outer wall and floor

		Primary = 0,
		// Inner wall and ceiling

		Secondary = 1,
		// Trim and misc

		Tertiary = 2,
		// Roof pieces

		Fourth = 3,
		// Invalid

		NumSlots = 4,
	};
}

UENUM()
namespace EFortTextureDataType
{
	enum Type
	{
		// Universal texture can be used anywhere

		Any = 0,
		// Outer wall texture, or both if no inner

		OuterWall = 1,
		// Applies to the inside edge of a wall

		InnerWall = 2,
		// Special textures for corner pieces

		Corner = 3,
		// Top of floor texture

		Floor = 4,
		// Bottom of floor/roof texture

		Ceiling = 5,
		// Detailed trim piece

		Trim = 6,
		// Roof texture

		Roof = 7,
		// Pillar texture

		Pillar = 8,
		// Extra roof texture

		Shingle = 9,
		// Invalid

		None = 10,
	};
}

USTRUCT(BlueprintType)
struct FFortBounceData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	float StartTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	float BounceValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	float Radius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	FLinearColor DeformationVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	FLinearColor DeformationCenter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	TEnumAsByte<EFortBounceType::Type> BounceType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BounceData")
	bool bLocalInstigator;

	UPROPERTY(Transient)
	bool bIsPlaying;

};

